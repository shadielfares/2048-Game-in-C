the-matrix: src/frontend/the-matrix.c src/frontend/gui.c include/gui.h src/backend/tile_generation.c include/tile_generation.h include/macros.h src/backend/slide.c include/slide.h src/backend/merge.c include/merge.h src/backend/scoring.c include/scoring.h
	gcc -o the-matrix src/frontend/the-matrix.c src/frontend/gui.c include/gui.h src/backend/tile_generation.c include/tile_generation.h include/macros.h src/backend/slide.c include/slide.h src/backend/merge.c include/merge.h src/backend/scoring.c include/scoring.h -lraylib -lglfw -lGL -lopenal -lm -lpthread -ldl -lrt -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor; sudo ldconfig;

# Rule to build the release version of the program
convert:
	gcc -o convert src/backend/2048_test_cases_files/2048_test_cases.c

# Rule to build the testing version with coverage enabled
ctest:
	gcc -o ctest --coverage src/backend/2048_test_cases_files/2048_test_cases.c
