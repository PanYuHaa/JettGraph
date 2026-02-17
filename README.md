# JettGraph
a graph be like jett


```shell
docker build -t jgraph:latest .
docker rm -f jg-dev
docker run -itd --name jg-dev -v "$(pwd)":/workspace -w "/workspace" jgraph:latest
docker exec -it jg-dev bash
```

```shell
mkdir -p build
cd build
cmake ..
make -j4
```