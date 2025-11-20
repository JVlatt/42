import argparse
import os
from pathlib import Path
import re
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import hashlib
import hmac
import struct
import time

def get_master_key() -> str:
    username = os.getenv("USER").encode()
    return hashlib.sha256(username).digest()


def encrypt_secret(secret_hex: str) -> str:
    key = get_master_key()
    cipher = AES.new(key, AES.MODE_ECB)
    encrypted = cipher.encrypt(pad(bytes.fromhex(secret_hex), 16))
    return encrypted


def decrypt_secret(encrypted: str) -> str:
    key = get_master_key()
    cipher = AES.new(key, AES.MODE_ECB)
    secret = unpad(cipher.decrypt(encrypted), 16)
    return secret.hex()


def generateKey(path: str) -> None:

    with open(path, "r") as f:
        content = f.read().strip()

        # 1 - Check Given File
        if not re.fullmatch(r"[0-9a-fA-F]{64,}", content):
            raise Exception(
                f"File {path} is invalid (must only contains hexadecimal characters and be at least 64 characters long)"
                )

        # 2 - Encrypt Key
        encryptedkey = encrypt_secret(content)
        with open("./ft_otp.key", "wb") as f:
            f.write(encryptedkey)


def getT() -> int :
    T0 = 0
    X = 60
    current_time = int(time.time())
    T = (current_time - T0) // X
    return T


def generatePassword(path: str) -> None:

    # 1 - Decrypt Key
    with open("./ft_otp.key", "rb") as f:
        key = decrypt_secret(f.read())
        key_bytes = bytes.fromhex(key)


        T_bytes = struct.pack(">Q", getT())
        HOTP = hmac.new(key_bytes, T_bytes, hashlib.sha1).digest()
        offset = HOTP[-1] & 0x0F
        binary = (
            ((HOTP[offset] & 0x7F) << 24) |
            ((HOTP[offset + 1] & 0xFF) << 16) |
            ((HOTP[offset + 2] & 0xFF) << 8) |
            (HOTP[offset + 3] & 0xFF)
        )
        otp = binary % 10**6
        print(otp)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-g", "--generate", help="Path to Hexadecimal Key")
    parser.add_argument("-k", "--key", help="Path to Key")
    args = parser.parse_args()

    try:
        if args.generate is not None:
            generateKey(args.generate)
        if args.key is not None:
            generatePassword(args.key)
    except Exception as e:
        print("Error:", e)


if __name__ == "__main__":
    main()
