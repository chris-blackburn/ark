CARGO := @cargo

.PHONY: all
all:
	$(CARGO) build

.PHONY: clean
clean:
	$(CARGO) clean
