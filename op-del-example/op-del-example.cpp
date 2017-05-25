#include <grpc++/grpc++.h>
#include <grpc++/impl/codegen/serialization_traits.h>
#include <grpc++/impl/codegen/async_unary_call.h>

namespace grpc {

template <>
class SerializationTraits<int, void>
{
public:
    static Status Serialize(const int&, grpc_byte_buffer**, bool*)
    {
        // proper implementation not needed for this example
        return Status::OK;
    }

    static Status Deserialize(grpc_byte_buffer*, int* )
    {
        // proper implementation not needed for this example
        return Status::OK;
    }
};

}  // namespace grpc


int main(int, char**)
{
    grpc::RpcMethod method("some-method", grpc::RpcMethod::NORMAL_RPC);
    grpc::ClientContext context;
    int msg = 100;

    auto carr = grpc::ClientAsyncResponseReader<int>::Create(
        nullptr,
        nullptr,
        method,
        &context,
        msg);

    return 0;
}
