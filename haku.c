#include "windows.h"
#include "stdio.h"
#include "time.h"

int main()
{
	HANDLE hMutexOne;
	char* MName1 = "uxJLpe1m"; #Modifica el nombre del mutex por el deseado
	char* MName2 = "Ap1mutx7";
    FILE* f;
    long tam;
    long max_tam = 50411050;
    time_t t; 

    DWORD esperando;
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    f = fopen("haku.log", "r");
    fseek(f, 0, SEEK_END);
    tam = ftell(f);
    fclose(f);

    if(tam>=max_tam) {
        f = fopen("haku.log", "w");
        remove("haku.log");
        fclose(f);
    }

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
