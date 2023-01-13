FROM emscripten/emsdk:latest

RUN apt-get update --allow-insecure-repositories

RUN apt-get install -y --allow-unauthenticated build-essential cmake clang-14 libboost-all-dev

COPY . /app

WORKDIR /app/native-code

RUN sh build.sh

WORKDIR /app/web-server

RUN npm install

EXPOSE 3000/tcp

CMD ["npm", "run", "dev"]
