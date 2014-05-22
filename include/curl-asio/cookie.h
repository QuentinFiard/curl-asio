/**
  curl-asio: wrapper for integrating libcurl with boost.asio applications
  Copyright (c) 2013 Oliver Kuckertz <oliver.kuckertz@mologie.de>
  See COPYING for license information.

  Class used to represent cookies.
*/

#pragma once

#include <chrono>
#include <string>
#include <boost/noncopyable.hpp>
#include "config.h"

namespace curl
{
  class CURLASIO_API cookie:
    public boost::noncopyable
  {
  public:
    typedef std::chrono::time_point<std::chrono::system_clock> time_point;
    cookie() {}

    const std::string &name() const;
    const std::string &value() const;
    const time_point &expiry() const;
    const std::string &path() const;
    const std::string &domain() const;
    bool secure() const;
    bool http_only() const;

    void set_name(const std::string &name);
    void set_value(const std::string &value);
    void set_expiry(const time_point &expiry);
    void set_path(const std::string &path);
    void set_domain(const std::string &domain);
    void set_secure(bool secure);
    void set_http_only(bool http_only);

  private:
    // Name of the cookie.
    std::string name_;
    // Value of the cookie.
    std::string value_;
    // Expiry of the cookie.
    time_point expiry_;
    // Path the cookie is good for.
    std::string path_;
    // Domain the cookie is good for.
    std::string domain_;
    // Need for a secure connection to use the cookie.
    bool secure_;
    // Whether or not the cookie can be accessed through other means than HTTP
    // (i.e., JavaScript).
    bool http_only_;
  };
}
