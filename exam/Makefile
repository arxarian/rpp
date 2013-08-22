.PHONY: xmi commit

xmi.zip: $(shell find xmi -mindepth 1)
	rm -f $@
	cd xmi && zip ../$@ *
	cd xmi && zip -r ../$@ .

xmi:
	rm -rf xmi
	unzip -d xmi xmi.zip

commit:
	git add -A xmi
	git commit
