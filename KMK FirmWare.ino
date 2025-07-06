import board, digitalio, neopixel
from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.scanners import DiodeOrientation
from kmk.extensions.RGB import RGB
from kmk.modules.combos import Combos
from kmk.handlers.sequences import Release
from kmk.scanners import KeysScanner

keyboard=KMKKeyboard()
combos=Combos()
keyboard.modules=[*keyboard.modules,combos]


PINS=[board.D7,board.D9, board.D6,
 board.D8,board.D10]

keyboard.matrix=KeysScanner(pins=PINS,value_when_pressed=False)

pixel_pin=board.D4;num_pixels=4

rgb_ext=RGB(pixel_pin=pixel_pin,num_pixels=num_pixels,hue_default=100,sat_default=100,val_default=30)

keyboard.extensions=[*keyboard.extensions, rgb_ext]

keyboard.keymap=[[KC.W,KC.A,KC.S,KC.D,KC.SPACE,Release(KC.LCMD)]]

keyboard.combos=[combos.Combo((1,2),KC.E,fast=True)]

if __name__=='__main__':keyboard.go()
