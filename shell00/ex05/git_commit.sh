git log | sed -n '/^commit/p' | sed 's/commit //' | sed -n 1,5p
