the-matrix: src/frontend/the-matrix.c src/frontend/gui.c include/gui.h src/backend/tile_generation.c include/tile_generation.h include/macros.h src/backend/slide.c include/slide.h src/backend/merge.c include/merge.h src/backend/scoring.c include/scoring.h
	gcc -o the-matrix src/frontend/the-matrix.c src/frontend/gui.c src/backend/tile_generation.c src/backend/slide.c src/backend/merge.c src/backend/scoring.c -lraylib -lglfw -lGL -lopenal -lm -lpthread -ldl -lrt -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor; sudo ldconfig;

backend-test: src/backend/test_cases.c src/backend/tile_generation.c include/tile_generation.h include/macros.h src/backend/slide.c include/slide.h src/backend/merge.c include/merge.h src/backend/scoring.c include/scoring.h
	gcc -o backend-test --coverage src/backend/test_cases.c src/backend/tile_generation.c src/backend/slide.c src/backend/merge.c src/backend/scoring.c
