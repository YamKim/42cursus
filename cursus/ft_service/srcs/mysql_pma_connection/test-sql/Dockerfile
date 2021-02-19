FROM alpine:3.12

RUN apk update
RUN	apk add mysql 
RUN mkdir -p /run/mysqld

COPY ./srcs/my.cnf /etc/mysql/
COPY ./srcs/init_db.sql /tmp/
COPY ./srcs/run.sh /usr/sbin/

EXPOSE 3306

ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
