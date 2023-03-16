#!/bin/bash

while true; do
  read -r -p "Do you wish to open report? (Y/N): " ANSWER
    case $ANSWER in
      [Yy]* ) x-www-browser report/index.html; break;;
      [Nn]* ) exit;;
      * ) echo "Please answer Y or N.";;
    esac
done