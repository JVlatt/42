import argparse
import re
import time
import base64
import hmac
import struct
import hashlib

def generateKey(path: str) -> None:

    with open(path, "r") as f:
        content = f.read().strip()

        # 1 - Check Given File
        if not re.fullmatch(r"[0-9a-fA-F]{64,}", content):
            raise Exception(
                f"File {path} is invalid (must only contains hexadecimal characters and be at least 64 characters long)"
                )

        # 2 - Encrypt Key
        key_bytes = bytes.fromhex(content)
        encryptedkey = base64.b32encode(key_bytes)
        with open("./ft_otp.key", "wb") as f:
            f.write(encryptedkey)


def getT() -> int :
    T0 = 0
    X = 30
    current_time = int(time.time())
    T = (current_time - T0) // X
    return T


def generateHOTP(secret: bytes, interval: int):
    key = base64.b32decode(secret, True)
    msg = struct.pack(">Q", interval)
    h = hmac.new(key, msg, hashlib.sha1).digest()
    o = o = h[19] & 15
    h = (struct.unpack(">I", h[o:o+4])[0] & 0x7fffffff) % 1000000
    return h


def generateTOTP(path: str) -> None:
    with open("./ft_otp.key", "rb") as f:
        x = str(generateHOTP(f.read(), getT()))
        while len(x)!=6:
            x = '0' + x
        return x


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-g", "--generate", help="Path to Hexadecimal Key")
    parser.add_argument("-k", "--key", help="Path to Key")
    args = parser.parse_args()

    try:
        if args.generate is not None:
            generateKey(args.generate)
        if args.key is not None:
            totp = generateTOTP(args.key)
            print(totp)
    except Exception as e:
        print("Error:", e)


if __name__ == "__main__":
    main()
