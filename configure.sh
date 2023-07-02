#!/bin/sh

CHECK_FOLDERS='build'

for folder in $(echo "$CHECK_FOLDERS" | sed "s/,/ /g"); do
  if [ ! -d "$folder" ]; then
    echo "Creating $folder..."
    mkdir "$folder"
  else
    echo "Nothing do do."
  fi
done
