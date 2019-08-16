for i in `find . -maxdepth 1 -name "*.cpp"`; do
	`mv $i Problems`;
	`git add Problems/$i`;
	git commit -m "adding problems"
done