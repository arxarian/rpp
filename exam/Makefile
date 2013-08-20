xmi.zip: $(shell find xmi)
	rm -f $@
	cd xmi && zip -r ../$@ .

xmi: xmi.zip
	rm -rf xmi
	unzip -d xmi $<
