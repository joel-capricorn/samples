all: setup_docker_images

Dockerfile.build:
	docker build -t abcd/alpine-build  -f Dockerfile.build .
	touch Dockerfile.build

.compile_challenges: Dockerfile.build src/Makefile
	docker run --rm -t -v ${PWD}/src:/src abcd/alpine-build make -f /src/Makefile
	sudo /usr/sbin/execstack --set-execstack src/output/Text*
	touch .compile_challenges

.Dockerfile.TextBookSample: Dockerfile.TextBookSample .compile_challenges
	docker build -t abcd/text-book-sample -f Dockerfile.TextBookSample .
	#docker tag -f abcd/text-book-stack gcr.io/abcde/text-book-stack:latest
	#gcloud docker push gcr.io/abcd/text-book-stack
	touch .Dockerfile.TextBookStack

setup_docker_images: .compile_challenges .Dockerfile.TextBookStack .Dockerfile.TextBookFormatString
	


