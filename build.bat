call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
cl skill_check.c /link gdi32.lib user32.lib
del *.obj
pause