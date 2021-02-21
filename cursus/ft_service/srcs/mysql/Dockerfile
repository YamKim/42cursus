FROM alpine:3.12

RUN apk update
RUN	apk add mysql 
RUN mkdir -p /run/mysqld

COPY ./srcs/mariadb-server.cnf /etc/my.cnf.d/
COPY ./srcs/init_db.sql /tmp/

COPY ./srcs/run.sh /usr/sbin/
RUN chmod +x /usr/sbin/run.sh

EXPOSE 3306

ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
