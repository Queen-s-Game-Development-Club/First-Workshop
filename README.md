# QGDC First Workshop - Intro to Godot Engine

Welcome!

## Setup Instructions

Ensure first that you have installed Visual Studio and the Godot Engine. We have
tested this to work with Visual Studio 2022 and Godot Engine v4.13-stable.

Godot: https://godotengine.org/
Visual Studio: https://visualstudio.microsoft.com/vs/

After cloning this repository, run,

```
scons platform=Windows
```

Then, create a file in demo/bin called gdexample.gdextension with the following
contents,

```
[configuration]

entry_symbol = "example_library_init"
compatibility_minimum = "4.1"

[libraries]

macos.debug = "res://bin/libgdexample.macos.template_debug.framework"
macos.release = "res://bin/libgdexample.macos.template_release.framework"
windows.debug.x86_32 = "res://bin/libgdexample.windows.template_debug.x86_32.dll"
windows.release.x86_32 = "res://bin/libgdexample.windows.template_release.x86_32.dll"
windows.debug.x86_64 = "res://bin/libgdexample.windows.template_debug.x86_64.dll"
windows.release.x86_64 = "res://bin/libgdexample.windows.template_release.x86_64.dll"
linux.debug.x86_64 = "res://bin/libgdexample.linux.template_debug.x86_64.so"
linux.release.x86_64 = "res://bin/libgdexample.linux.template_release.x86_64.so"
linux.debug.arm64 = "res://bin/libgdexample.linux.template_debug.arm64.so"
linux.release.arm64 = "res://bin/libgdexample.linux.template_release.arm64.so"
linux.debug.rv64 = "res://bin/libgdexample.linux.template_debug.rv64.so"
linux.release.rv64 = "res://bin/libgdexample.linux.template_release.rv64.so"
android.debug.x86_64 = "res://bin/libgdexample.android.template_debug.x86_64.so"
android.release.x86_64 = "res://bin/libgdexample.android.template_release.x86_64.so"
android.debug.arm64 = "res://bin/libgdexample.android.template_debug.arm64.so"
android.release.arm64 = "res://bin/libgdexample.android.template_release.arm64.so"
```

each time you would like to rebuild the code in the GDExtension, run,

```
scons platform=Windows
```

I've found that this only works when the Godot editor is closed. There must be a
better way. But for the purpose of this tutorial, this is what we got.
