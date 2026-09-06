# Security Tips & Best Practices

To stay undetected and keep your account safe, follow these rules:

1. **Rename Everything**: Never name your executable `Cheat.exe`. Use something generic like `Calculator.exe` or `svchost_task.exe`.
2. **Driver is Key**: Do not use standard Windows APIs like `ReadProcessMemory`. Always implement your memory operations through a Kernel Driver.
3. **Avoid Strings**: Don't use obvious strings like "Aimbot" or "ESP" in your window titles. Our base randomizes the class name, but keep your UI text clean or obfuscated if possible.
4. **No Compile while Gaming**: Close your game before compiling your project. Anticheats can monitor file system changes and handle creations.
5. **Entropy**: If possible, add some "junk code" or change your UI layout frequently to change your file's signature.


*Stay safe and respect the learning curve.*
