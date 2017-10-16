# Mercury-Cheat Training Software
![banner](http://i.imgur.com/w96wdtE.png)

## Discord Server
[Official Discord Server](https://discord.gg/xBGG56j

Mercury-Cheat is a training software designed for Team Fortress 2 for Linux. Mercury-Cheat includes some joke features like

* Backpack.TF API integration with playerlist GUI, allowing you to see players' inventory values
* Always/Never spycrab
* Ignore Hoovy
* 100% Casual/Comp coin flip
* Encrypted chat
* Emoji ESP
* Fidget Spinner crosshair

and a lot of useful features, including

* Anti Backstab with option to say "No" voice command when spy tries to backstab you
* Heal Arrows exploit (overheal an enemy for 1200 health with single huntsman arrow, you can also do it with buildings!)
* Extremely customizable spam (you can make spam lines that'll include name of random dead enemy pyro or sniper)
* Follow Bots
* Working crit hack

[FULL LIST OF FEATURES HERE](https://github.com/xConModz/Mercury-Cheat/wiki/List-of-features)

# INSTALLATION

You can use gcc-7 for compiling Mercury-Cheat if you add `-e CC=gcc-7 CXX=g++-7` to make command line

Ubuntu gcc6 installation: (check if you have gcc-6 installed already by typing `gcc-6 -v`
```bash
sudo apt update && sudo apt install build-essential software-properties-common -y && sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y && sudo apt update && sudo apt install gcc-snapshot g++-6-multilib gcc-6 g++-6 -y
```

Ubuntu other dependencies installation:

```bash
sudo apt update && sudo apt install git libssl-dev:i386 libc6-dev:i386 gdb libsdl2-dev libglew-dev:i386 libfreetype6-dev:i386 -y 
```


Arch gcc6 & dependencies installation:
```bash
sudo pacman -U /var/cache/pacman/pkg/lib32-gcc-libs-6.3.1-2-x86_64.pkg.tar.xz /var/cache/pacman/pkg/gcc-libs-multilib-6.3.1-2-x86_64.pkg.tar.xz /var/cache/pacman/pkg/gcc-multilib-6.3.1-2-x86_64.pkg.tar.xz && sudo cp -r /usr/include/c++/6.3.1/ /tmp/ && sudo pacman -S gdb gdb-common glew1.10 glew lib32-glew1.10 rsync lib62-gcc-libs gcc-libs-multilib gcc-multilib --noconfirm && yes | sudo cp -r  /tmp/6.3.1/ /usr/include/c++/
```

If you don't use Ubuntu or Arch (or if Arch script gets outdated), here's the list of what Mercury-Cheat requires:

* `gcc-6`
* `g++-6`
* `gcc-6-multilib`
* `g++-6-multilib`
* `glew`
* `gdb` (for the injection script, you can use different injector if you want)
* `libssl-dev:i386`
* `libc6-dev:i386`
* `libsdl2-dev`
* `libglew-dev:i386`
* `libfreetype6-dev:i386`
* `rsync` (used for copying shaders/fonts to tf2 data directory, `update-data` script)


Mercury-Cheat installation script:
```bash
git clone --recursive https://github.com/nullifiedcat/Mercury-Cheat && cd Mercury-Cheat && bash build-tf2 && bash update-data
```

**Errors while installing?**

`/usr/include/c++/5/string:38:28: fatal error: bits/c++config.h: No such file or directory`
You don't have gcc-multilib-6 installed correctly.

`src/<any file>: fatal error: mathlib/vector.h: No such file or directory`
You didn't download Source SDK. **DO NOT DOWNLOAD Mercury-Cheat USING "DOWNLOAD .ZIP" FROM GITHUB. USE git clone --recursive!**

If you are using another distro, make sure to have g++-6, gdb, libc6 and build essentials installed.

## Updating Mercury-Cheat
Run the `update` script in Mercury-Cheat folder.

Mercury-Cheat requires a special data folder (contains shaders, font files, walkbot paths, etc). This folder is located at `/opt/Mercury-Cheat/data` and is generated automatically when you compile Mercury-Cheat.

## Injection
`sudo ./attach` to attach Mercury-Cheat into TF2. Optionally, you can provide an argument number (0-n - #) to provide the TF2 process ID (for bots).

`sudo ./attach-backtrace` to attach and print backtrace incase TF2 crashes. Some users report that this causes FPS drop in-game. This is recommended to grab a log of what went wrong if Mercury-Cheat is crashing on you.

## Followbots (outdated)
`Mercury-Cheat-ipc-server` allows you to run and control Followbots to do your evil bidding in-game. The installation for Followbots is quite complex, and will not be covered on this page. Obviously, you must have several user accounts ready to run TF2.  
A guide for Followbots can be found here: [How to setup and use followbots.](https://www.youtube.com/watch?v=kns5-nw7xUg)  
You may also ask someone in our discord server to help you out.

The installation script is as followed:
```bash
git clone --recursive https://github.com/nullifiedcat/Mercury-Cheat-ipc-server && cd Mercury-Cheat-ipc-server && make -j4
```
To run the Followbot server, run `./bin/Mercury-Cheat-ipc-server`. You can also use `./bin/Mercury-Cheat-ipc-server &>/dev/null &` to run it in background.
