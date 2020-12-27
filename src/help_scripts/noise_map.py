from PIL import Image
import sys
import random


SEED = input("Podaj seed: ")
random.seed(SEED)

MAP_SIZE = int(input("Podaj rozmiar obrazu: "))

img = Image.new('RGB', (MAP_SIZE, MAP_SIZE))

for x in range(MAP_SIZE):
    for y in range(MAP_SIZE):
        if random.randint(0, 1) == 0:
            color = (255,255,255)
        else:
            color = (0,0,0)
        img.putpixel( (x,y), color )

img.show()

img.save("noise_map.png")


