# Bong-WM - personal dwm+slstatus build
## dwm
### Patches:
- [fullgaps](https://dwm.suckless.org/patches/fullgaps/)
- [systray](https://dwm.suckless.org/patches/systray/)

### Dependencies (apart from official ones; you wouldn't try a custom build before trying stock, would you?):
- [pamixer](https://github.com/cdemoulins/pamixer) (for volume bindings; same can be done with pactl, cf [i3-gaps example config](https://github.com/Airblader/i3/blob/gaps-next/etc/config#L37) for those)
- [brightnessctl](https://github.com/Hummer12007/brightnessctl) (for brightness bindings)

## slstatus
### Custom bash scripts:
- **Volume module** (`sl-vol`): the stock one uses ALSA, mine uses PulseAudio (Pipewire-compatible) + a Material Icon indicator changing depending on the volume level. Also stolen from [Joe Standring](https://github.com/joestandring/dwm-bar/blob/master/bar-functions/dwm_pulse.sh).
- **Brightness module** (`sl-bkl`): not provided by stock slstatus + a similar Material Icon indicator.

### Dependencies:
- pamixer (for `sl-vol`; the `pactl info` output was too clumsy to extract the percentage from it, and pamixer is able to output only a number)
- brightnessctl (for `sl-bkl`; yes, the command is clumsy af compared to [light](https://github.com/haikarainen/light), but a) I got used to `brightnessctl` and b) I found a [solution](https://github.com/Hummer12007/brightnessctl/issues/55#issuecomment-732945350) for this)
- [Material Icons font](https://materialdesignicons.com/) (for indicators ofc)

## Installation
1. `cd` into the corresponding folder (`dwm`, then `slstatus`).
2. Review the code. Would you trust a stranger on Github, whose repo has zero stars and watchers? Also, if you're on BSD, some parameters in `slstatus.h` are different for BSD and Linux (i'm a Linux user ~~btw~~): edit them accordingly (the long-ass comment with modules' descriptions is made by devs, kudos to them for it).
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
6. ???
7. PROFIT!!1!

Enjoy ~~while you still can~~

## Plans
- change dwm's colour scheme
- apply the "focusonclick" patch
- replace brightnessctl with light
