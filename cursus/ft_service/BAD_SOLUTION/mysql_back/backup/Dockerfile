FROM alpine:3.12

RUN apk update
RUN apk add mariadb
RUN apk add mariadb-client
RUN rm -rf /var/cache/apk/*

#RUN mkdir -p /run/mysqld
#RUN service mysql start

#COPY srcs/my.cnf /etc/mysql/my.conf
#COPY srcs/mysql-init /tmp/mysql-init
#COPY srcs/start.sh /tmp/start.sh
COPY srcs/db_init.sql /tmp/
COPY srcs/wordpress.sql /tmp/
COPY srcs/run.sh /tmp/
COPY srcs/start.sh /tmp/

#RUN service mysql start && mysql -u root < /tmp/mysql-init
RUN chmod +x /tmp/run.sh
RUN chmod +x /tmp/start.sh

EXPOSE 3306

WORKDIR /tmp/

ENTRYPOINT start.sh
