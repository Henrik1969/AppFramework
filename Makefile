#
#  This file is part of the AppFramework project.
#
#  AppFramework is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, GPL version 4.
#
#  AppFramework is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License version 4 for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with AppFramework. If not, see <https://www.gnu.org/licenses/>.
#

.PHONY: rebuild clean git-add git-commit git-push list-targets help

rebuild:
	@COMPILER_FLAGS=$(shell cat config/active_flags.conf) \
	rm -rf build/ && \
	mkdir build && \
	cd build && \
	cmake .. $$COMPILER_FLAGS && \
	make
	@echo "Project Rebuild Complete"
mr-proper:
	@if [ -d "build" ]; then \
		rm -rf build\
	else \
		echo "Build directory does not exist"; \
	fi
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

todo-list:
	@echo "Listing all TODOs in the project..."
	@grep -rn '//Todo:' . --exclude=Makefile
# Define the help message
HELP_MSG := "\
Available targets:\n\
	rebuild        	:Rebuild the project\n\
	clean          	:Clean the project\n\
	mr-proper		:Remove the build directory\n\
	git-add        	:Add all changes to Git\n\
	git-commit     	:Commit changes to Git\n\
	git-push       	:Push changes to the remote repository\n\
	list-targets:  	:List all available targets\n\
	help           	:Display this help message\n"

# The default target is 'help', so running 'make' or 'make help' will display the help message.
help:
	@echo $(HELP_MSG)