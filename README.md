# OS-Toolbox

Tools and Projects for CS 351 (McCarthy)
I recreated the VM [originally linked here](https://www.os-book.com/OS10/index.html), because a headless instance of Ubuntu sucks.

# Extra Notes

- [Remapping CAPS to ESC in Ubuntu 16.04](https://era86.github.io/2017/01/14/remapping-capslock-to-escape-in-ubuntu-1604.html)
    * ```bash
    sudo apt-get install dconf-tools
    dconf write /org/gnome/desktop/input-sources/xkb-options "['caps:escape']"
    ```
