# Haku
Un simple código en C que protege el equipo ante determinadas infecciones mediante la creación de objetos de exclusión mutua utiliados por algunas familias de malware como "marca de infección".

__HOW TO USE:__

- En el fichero haku.c, asigna el nombre del mutex creado por el malware a las variables MName*. Puedes definir tantas variables como mutex desees crear.
- Compila el código
- Execute & Enjoy!!!

__Para generar persistencia en el arranque del sistema crea una entrada con la ruta donde se encuentre el ejecutable en:__

HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run
HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run
