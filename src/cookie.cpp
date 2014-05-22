#include <curl-asio/cookie.h>

namespace curl {

const std::string &cookie::name() const { return name_; }
const std::string &cookie::value() const { return value_; }
const cookie::time_point &cookie::expiry() const { return expiry_; }
const std::string &cookie::path() const { return path_; }
const std::string &cookie::domain() const { return domain_; }
bool cookie::secure() const { return secure_; }
bool cookie::http_only() const { return http_only_; }

void cookie::set_name(const std::string &name) { name_ = name; }
void cookie::set_value(const std::string &value) { value_ = value; }
void cookie::set_expiry(const time_point &expiry) { expiry_ = expiry; }
void cookie::set_path(const std::string &path) { path_ = path; }
void cookie::set_domain(const std::string &domain) { domain_ = domain; }
void cookie::set_secure(bool secure) { secure = secure_; }
void cookie::set_http_only(bool http_only) { http_only_ = http_only; }

}  // namespace curl
