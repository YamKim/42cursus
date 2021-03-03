FROM alpine:3.12

RUN apk update 
RUN apk add nginx
RUN apk add openssh
RUN rm -rf /var/cache/apk/*

COPY ./srcs/index.html /var/www/index.html
COPY ./srcs/sshd_config /etc/ssh/sshd_config
COPY ./srcs/run.sh /usr/sbin/run.sh

RUN ssh-keygen -A
RUN chmod +x /usr/sbin/run.sh

EXPOSE 22 80 443

#ENTRYPOINT ["/usr/sbin/run.sh"]
