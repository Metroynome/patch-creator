# patch-creator
Takes advantage of the patch.bin file from Ratchet: Deadlocked or Ratchet: Gladiator and lets you insert your own code.

## Build with docker
Clone Repo:
```sh
git clone https://github.com/Metroynome/patch-creator.git
cd patch-creator
```

Get PS2SDK via docker:
```sh
docker pull ps2dev/ps2dev:v1.2.0
docker run -it --rm -v "$PWD\:/src" ps2dev/ps2dev:v1.2.0
cd src
./docker-init.sh
```

Make it:
```sh
make clean && make
```
