FROM alpine:3.12

RUN apk update 
RUN apk add nginx
RUN apk add openssh
#RUN apk add --no-cache
RUN rm -rf /var/cache/apk/*

COPY ./srcs/index.html /var/www/index.html
COPY ./srcs/start.sh /usr/sbin/start.sh
COPY ./srcs/sshd_config /etc/ssh/sshd_config

RUN ssh-keygen -A
RUN chmod +x /usr/sbin/start.sh

EXPOSE 22 80 443

#WORKDIR /usr/sbin/

ENTRYPOINT ["/usr/sbin/start.sh"]
