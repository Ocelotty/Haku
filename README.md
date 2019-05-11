# Haku
Un simple código en C que permite el uso de las marcas de infección de determinados malwares como vacuna para su prevención (en esta primera versión mediante la creación de objetos de exclusión mutua).

__HOW TO USE:__

- En el fichero haku.c, asigna el nombre del mutex creado por el malware a las variables MName*. Puedes definir tantas variables como mutex desees crear.
- Compila el código
- Execute & Enjoy!!!

__Para generar persistencia en el arranque del sistema crea una entrada en:__

HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run
HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run
