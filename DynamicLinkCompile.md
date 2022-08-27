gcc -c src/ProjectManager.c -o bin/ProjectManager

gcc -c -fPIC src/imports/create_directory.c -o bin/shared/create_directory.o

gcc -c -fPIC src/imports/create_feature.c -o bin/shared/create_feature.o

gcc -c -fPIC src/imports/remove_directory.c -o bin/shared/remove_directory.o

gcc -c -fPIC src/imports/view_directory.c -o bin/shared/view_directory.o

gcc -c -fPIC src/imports/search_directories.c -o bin/shared/search_directories.o

gcc -c -fPIC src/imports/move_directory.c -o bin/shared/move_directory.o

gcc -c -fPIC src/imports/read_and_write.c -o bin/shared/read_and_write.o

gcc -shared bin/shared/create_directory.o bin/shared/create_feature.o bin/shared/remove_directory.o bin/shared/view_directory.o bin/shared/search_directories.o bin/shared/move_directory.o bin/shared/read_and_write.o -o bin/shared/libimports.so

gcc  bin/ProjectManager -Lbin/shared -limports -o bin/LinkedProjectManager

sudo mv bin/shared/libimports.so /lib
