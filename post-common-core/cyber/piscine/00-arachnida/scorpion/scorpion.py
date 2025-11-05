from PIL import Image

def main():
    img = Image.open("photo.jpg")
    exif_data = img._getexif()
    print(exif_data)



if __name__ == "__main__":
    main()
