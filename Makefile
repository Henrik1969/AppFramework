.PHONY: rebuild clean

rebuild:
	@rm -rf build/
	@mkdir build
	@cd build && cmake .. && make
	@echo "Project Rebuild Complete"

clean:
	@if [ -d "build" ]; then \
		cd build && make clean; \
		cd ..; \
		echo "Cleaned build directory"; \
	else \
		echo "Build directory does not exist"; \
	fi
