// Spawn.cpp - this program launches any program or document minimized - so no window ever pops up!

#include <windows.h>
#include <stdio.h>

wchar_t szName[1024];
wchar_t szParm[4096];

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	int i;
	LPWSTR *szArgs;
	int nArgs = 0;

	szArgs = CommandLineToArgvW(GetCommandLine(), &nArgs);
	if (NULL == szArgs) {
		wprintf(L"Couldn't parse arguments\n");
		return 0;
	}
	if (nArgs < 2) {
		wprintf(L"Need at least one program argument!\n");
		return 0;
	}

	wcscpy(szName, szArgs[1]);
	wcscpy(szParm, L"");

	for (i=2; i<nArgs; i++) {
		if (i > 2) wcscat(szParm, L" ");
		wcscat(szParm, szArgs[i]);
	}

	ShellExecute(NULL, NULL, szName, szParm, NULL, SW_MINIMIZE);

	Sleep(1000);

	LocalFree(szArgs);

	return(0);
}
