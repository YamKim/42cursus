FROM alpine:3.12

RUN apk update
RUN apk add mysql
RUN apk add mysql-client
RUN rm -rf /var/cache/apk/*

RUN mkdir -p /run/mysqld

COPY srcs/my.cnf /etc/mysql/my.conf
COPY srcs/mysql-init /tmp/mysql-init
COPY srcs/start.sh /tmp/start.sh

EXPOSE 3306

ENTRYPOINT ["sh", "/tmp/start.sh"]
