.PHONY: rebuild clean git-add git-commit git-push list-targets help

rebuild:
	@COMPILER_FLAGS=$(shell cat config/active_flags.conf) \
	rm -rf build/ && \
	mkdir build && \
	cd build && \
	cmake .. $$COMPILER_FLAGS && \
	make
	@echo "Project Rebuild Complete"
clean:
	@if [ -d "build" ]; then \
		cd build && make clean; \
		cd ..; \
		echo "Cleaned build directory"; \
	else \
		echo "Build directory does not exist"; \
	fi
# Git-related targets
git-add:
	@echo "Adding all changes to Git..."
	git add .

git-commit:
	@echo "Committing changes..."
	git commit

git-push:
	@echo "Pushing to remote repository..."
	git push

list-targets:
	@grep -E '^[a-zA-Z0-9_-]+:' $(MAKEFILE_LIST) | awk -F':' '{print $$1}' | grep -v '^list-targets$$'

# Define the help message
HELP_MSG := "\
Available targets:\n\
	rebuild        :Rebuild the project\n\
	clean          :Clean the project\n\
	git-add        :Add all changes to Git\n\
	git-commit     :Commit changes to Git\n\
	git-push       :Push changes to the remote repository\n\
	list-targets:  :List all available targets\n\
	help           :Display this help message\n"

# The default target is 'help', so running 'make' or 'make help' will display the help message.
help:
	@echo $(HELP_MSG)