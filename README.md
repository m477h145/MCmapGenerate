# mapGenerate
### a quick and dirty script to pre-Generate maps for Minecraft servers


# Content
* [Prerequisites](#prerequisites)
* [How to build](#how-to-build)
* [How to use](#how-to-use)
* [FAQ](#faq)


# Prerequisites

- GNU/Linux
- GCC (should be preinstalled on Linux)
- Screen (the Linux program, duh)
- A minecraft server
- A minecraft account


# How to build (Optional)
There should be an executable provided in the Releases section but if you don't trust me (you generally shouldn't trust a random person on the internet) here's how to compile it yourself.

To build, run:
```
gcc -o mapGenerate mapGenerate.c -lm
``` 


# How to use

1. Place the executable as well as the shell script (teleport.sh) inside the same folder on the server.
2. Launch executable

   ```
   ./mapGenerate
   ```
   If you get an error related to not beeing able to execute it just:

   ```
   chmod +x mapGenerate
   ```

3. Adjust the settings to your liking as well as set the screen- and MC username
4. Join server with player and change to spectator mode
5. Run script
6. ...
7. Profit
 

# FAQ
There actually havn't been any questions yet but who cares.

- ##### Why C!?
   I go to engineering school, we don't get fancy languages. jk
   It's what I'm most comfortable with and I couldn't be bothered to learn python for such a tiny project.

- ##### What's the point?
   To prevent excessive laggs from map generation during the beginning of medium to large SMP servers when many players are exploring at once.
   The idea was popularized (afaik) by [Xisumavoid](https://www.youtube.com/watch?v=eA35S2GW-jI) and used on the Hermitcraft server.

- ##### How to improve the idea?
   Install a Desktop Environment onto the server (openbox, lxde, something lightweight) and run the client directly on the server.

- ##### Did I really spent time making a ReadMe?
   Yes