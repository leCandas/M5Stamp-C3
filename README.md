## This is an example PlatformIO project for M5Stamp C3
Internal led will change its color with each press on the button.

## set-up:

- You will need riscv32-esp-elf downloaded use link 

https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/tools/idf-tools.html#riscv32-esp-elf

- Extract the downloaded zip to somewhere
- Put your old "package.json" in to the extracted folder 
  you can find it under "\userhome\\.platformio\packages\toolchain-riscv32-esp"
  
- finally set the correct path in platfromio.ini

  toolchain-riscv-esp@file://[CHANGE ME!]/riscv32-esp-elf, replace [CHANGE ME!] with correct path.
