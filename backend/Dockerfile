FROM alpine:latest

WORKDIR /app
COPY app.cpp .

RUN apk add --no-cache g++ \
    && g++ app.cpp -o app

CMD ["./app"]
