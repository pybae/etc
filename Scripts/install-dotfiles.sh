#!/usr/bin/env bash

if hash stow 2>/dev/null; then
    echo "Installing with stow"
    echo "===================="
    cd $HOME
    git clone https://github.com/pybae/dotfiles

    cd dotfiles
    stow git tmux vim zsh
else
    echo "Stow not found, manual installation required."
    echo "You can clone my dotfiles at github.com/pybae/dotfiles"
fi

echo "Installation complete!"
echo "You can find more info about my dotfiles at github.com/pybae/dotfiles,
thank you for installing!"
