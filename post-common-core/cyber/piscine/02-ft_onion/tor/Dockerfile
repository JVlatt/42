FROM debian:12-slim

RUN apt-get update && apt-get install -y --no-install-recommends gnupg wget ca-certificates

RUN wget -qO- https://deb.torproject.org/torproject.org/A3C4F0F979CAA22CDBA8F512EE8CBC9E886DDD89.asc \
     | gpg --dearmor -o /usr/share/keyrings/tor-archive-keyring.gpg

RUN echo \
  "deb [signed-by=/usr/share/keyrings/tor-archive-keyring.gpg] \
  https://deb.torproject.org/torproject.org bookworm main" \
  > /etc/apt/sources.list.d/tor.list

RUN apt-get update \
 && apt-get install -y --no-install-recommends tor \
 && rm -rf /var/lib/apt/lists/*

USER debian-tor
COPY torrc /etc/tor/torrc
VOLUME ["/var/lib/tor"]
CMD ["tor", "-f", "/etc/tor/torrc"]
