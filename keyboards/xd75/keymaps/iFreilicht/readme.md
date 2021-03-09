# iFreilicht's custom keymap for xd75

This keymap offers a split layout based on the US-International layout.
It requires the layout "US-INTL" (with dead keys) to be selected in OS.
The dead keys are "revived" to be used exactly like non-dead keys, similar to how linux
handles the "AltGr dead keys" variant of the layout. They can still be accessed via the FN layer.

[Check out the full layout on KLE](http://www.keyboard-layout-editor.com/#/gists/f0196aab501bc234ef708e5527d6ad31):

The "Num Mode Lock" and "Game Mode Lock" buttons are implemented as Locking MX switches on my board.
If you want to use regular switches, change the respective instances of `MO()` to `TG()` before compiling.
