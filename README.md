# Bong-WM - personal dwm+slstatus build
## dwm
### Patches:
- [fullgaps](https://dwm.suckless.org/patches/fullgaps/), specifically - its toggle version, which has an option to reset changed gaps to the numbers set in `config.h`
- [systray](https://dwm.suckless.org/patches/systray/)
- [focus on click](https://dwm.suckless.org/patches/focusonclick/)

### Dependencies (apart from official ones; you wouldn't try a custom build before trying stock, would you?):
- [pamixer](https://github.com/cdemoulins/pamixer) (for volume bindings; same can be done with pactl, cf [i3-gaps example config](https://github.com/Airblader/i3/blob/gaps-next/etc/config#L37) for those)
- [brightnessctl](https://github.com/Hummer12007/brightnessctl) (for brightness bindings)
- Iosevka (my default font; you can replace it with your favourite one)
- Material Icons (it actually should be installed in the system for status bar icons (or maybe custom tag names) to work, and also declared in the dwm's config to be displayed properly and consistently)
- Alacritty (terminal; you can also replace it)
- Rofi (app menu/launcher/whatever menu you want it to be; used instead of dmenu\*; also replaceable)
- [Scrotre](https://github.com/dyeo/scrotre) (fork of [escrotum](https://github.com/Roger/escrotum), commands declared in the config are fully compatible (if you replace `scrotre` with `escrotum`))

## slstatus
### Custom bash scripts:
- **Volume module** (`sl-vol`): the stock one uses ALSA, mine uses PulseAudio (Pipewire-compatible) + a Material Icon indicator changing depending on the volume level. Also stolen from [Joe Standring](https://github.com/joestandring/dwm-bar/blob/master/bar-functions/dwm_pulse.sh).
- **Brightness module** (`sl-bkl`): not provided by stock slstatus + a similar Material Icon indicator.

### Dependencies:
- pamixer (for `sl-vol`; the `pactl info` output was too clumsy to extract the percentage from it, and pamixer is able to output only a number)
- brightnessctl (for `sl-bkl`; yes, the command is clumsy af compared to [light](https://github.com/haikarainen/light), but a) I got used to `brightnessctl` and b) I found a [solution](https://github.com/Hummer12007/brightnessctl/issues/55#issuecomment-732945350) for this)
- [Material Icons font](https://materialdesignicons.com/) (for indicators ofc)

## Installation
0. `git clone` the repo in the preferred folder.
1. `cd` into the corresponding folder (`dwm`, then `slstatus`).
2. Review the code. Would you trust a stranger on Github, whose repo has zero stars and watchers? Also, if you're on BSD, some parameters in `slstatus.h` are different for BSD and Linux (i'm a Linux user ~~btw~~): edit them accordingly (the long-ass comment with modules' descriptions is made by devs, kudos to them for it). Also make sure to change the device name in `sl-bkl` to yours (check in the `brightnessctl` output). 
3. Run in each of the folders (`dwm` and `slstatus`) `sudo make clean install` (or `doas <...>`, if you're a BSD user or a kinky Linuxoid).
4. Put the `bin` folder in `~` or `~/.local`. Add the resulted folder into your $PATH environment variable in your `~/.bashrc` or `~/.zshrc`:
```
export PATH=$PATH:$HOME/.local/bin
```
or
```
export PATH=$PATH:$HOME/bin
```
5. Add both slstatus and dwm in your `~/.xinitrc` (or make an xsession, if you'd like to use a DM).
6. Make em launchable:
  
  a) edit your `~/.xinitrc` or `~/.config/sx/sxrc`:
```
slstatus &
exec dwm
# or, if you wish to reload dwm without logging out/killing X, replace `exec dwm` with these:
# while true; do
# 	dwm >/dev/null 2>&1
# done
```
OR

  b) create an X session at `/usr/share/xsessions/dwm.desktop`:
```
[Desktop Entry]
Encoding=UTF-8
Name=Dwm
Comment=Dynamic window manager
Exec=dwm
Icon=dwm
Type=XSession
```
  
7. ???
8. PROFIT!!1!

Enjoy ~~while you still can~~

## Plans
- Change dwm's colour scheme
- ~~Apply the "focusonclick" patch~~
- ~~Replace brightnessctl with light~~
  - Well, nah. `light`'s output isn't an integer and i'm too lazy to cut off the decimals, so I'll stick to brightnessctl. If it works, it works.
- Apply the "[tag previews](https://dwm.suckless.org/patches/tag-previews/)" patch (yup, i'm a mouse normie)
- Try "[taglabels](https://dwm.suckless.org/patches/taglabels/)" patch (maybe i'll finally create new tags/branches for different patches)
- Finally add more comments into the config. For default options too
- **DONE** Make `dmenucmd` ~~great again~~ launch rofi.
- Try [extrabar](https://dwm.suckless.org/patches/extrabar/), [colorbar](https://dwm.suckless.org/patches/colorbar/), https://dwm.suckless.org/patches/selfrestart/, https://dwm.suckless.org/patches/pertag/
