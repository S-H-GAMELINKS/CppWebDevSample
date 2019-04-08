# CppWebDevSample
## What's This?

Web Application Sample! Development by C++/Vue.js/Stimulus/Webpack/Node.js/Docker!

# Usage

First, build `gcc` image.

```shell
docker build -t cpp-web-dev .
```

Move to `static`

```shell
cd static
```

And, build 

```shell
yarn install && yarn build
```

Last, Docker container run!

```shell
docker run --rm --name cpp-web-dev -i -p 3000:3000 -t cpp-web-dev
```

Access to `localhost:3000`!

Enjoy it!

# License

[MIT](./LICENSE)
