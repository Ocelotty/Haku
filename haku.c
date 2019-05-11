#include "windows.h"
#include "stdio.h"
#include "time.h"

int main()
{
	HANDLE hMutexOne;
	char* MName1 = "*"; //-->Asignar el nombre del mutex creado por el malware.
	char* MName2 = "*"; //-->Asignar el nombre del mutex creado por el malware.
    FILE* f;
    long tam;
    long max_tam = 50411050;
    time_t t; 

    DWORD esperando;
    //Puedes comentar las dos líneas siguientes si no quieres que se oculte la ventana
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    //Por defecto el log se crea en el mismo directorio donde se guarde el ejecutable
    f = fopen("haku.log", "r");
    fseek(f, 0, SEEK_END);
    tam = ftell(f);
    fclose(f);

    if(tam>=max_tam) {
        f = fopen("haku.log", "w");
        remove("haku.log");
        fclose(f);
    }
        //Creación del mutex, para más mutex copia y pega todo el contenido, cambiando el MName*
	//INICIO
	hMutexOne = CreateMutex(NULL, TRUE, MName1);
	if (hMutexOne == NULL) {
        f = fopen("haku.log", "a+");
        time(&t);
		fprintf(f, "%.24s: Ha habido un error desconocido: %d \n", ctime(&t), GetLastError());
        fclose(f);
	}
	else {
        if (GetLastError() == ERROR_ALREADY_EXISTS) {
            f = fopen("haku.log", "a+");
            time(&t);
            fprintf(f, "%.24s: Fichero mutex ya existente %s \n", ctime(&t), MName1);
            fclose(f);
            esperando=WaitForSingleObject(hMutexOne, INFINITE);
            hMutexOne = CreateMutex(NULL, TRUE, MName1);
            f = fopen("haku.log", "a+");
            time(&t);
            fprintf(f, "%.24s: Desocupado y creado, con nombre %s y ID de espera: %d \n", ctime(&t), MName1, esperando);
            fclose(f);
            
		}
        else {
            f = fopen("haku.log", "a+");
            time(&t);
            fprintf(f, "%.24s: Mutex creado: %s \n", ctime(&t), MName1);
            fclose(f);
        }
    }
	//FIN
	hMutexOne = CreateMutex(NULL, TRUE, MName2);
	if (hMutexOne == NULL) {
        f = fopen("haku.log", "a+");
        time(&t);
		fprintf(f, "%.24s: Ha habido un error desconocido: %d \n", ctime(&t), GetLastError());
        fclose(f);
	}
	else {
        if (GetLastError() == ERROR_ALREADY_EXISTS) {
            f = fopen("haku.log", "a+");
            time(&t);
            fprintf(f, "%.24s: Fichero mutex ya existente %s \n", ctime(&t), MName2);
            fclose(f);
            esperando=WaitForSingleObject(hMutexOne, INFINITE);
            hMutexOne = CreateMutex(NULL, TRUE, MName2);
            f = fopen("haku.log", "a+");
            time(&t);
            fprintf(f, "%.24s: Desocupado y creado, con nombre %s y ID de espera: %d \n", ctime(&t), MName2, esperando);
            fclose(f);
            
		}
        else {
            f = fopen("haku.log", "a+");
            time(&t);
            fprintf(f, "%.24s: Mutex creado: %s \n", ctime(&t), MName2);
            fclose(f);
        }
    }

	while(1){
		Sleep(10000);
	}
	return 0;
}
