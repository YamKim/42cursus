FROM alpine:3.12

RUN apk update
RUN	apk add nginx
RUN apk add openssl 
RUN apk add openssh 
RUN rm -rf /var/cache/apk/*

COPY ./srcs/default.conf /etc/nginx/conf.d/
COPY ./srcs/index.html /var/www/
COPY ./srcs/run.sh /usr/sbin/
COPY ./srcs/sshd_config /etc/ssh/

RUN chmod +x /usr/sbin/run.sh

EXPOSE 80 443 22

RUN mkdir -p /run/nginx
ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
