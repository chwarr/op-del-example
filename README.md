# `ClientAsyncResponseReader` mismatched placement new/delete demonstration program

This repository demonstrates a build warning issued by Visual C++ 2016 x64
from gRPC++'s `ClientAsyncResponseReader`.

Pre-requisites:

* Visual Studio 2015
* CMake 3.1
* gRPC++'s pre-requisites

To see the warning, run:

```
PS> git clone --recursive https://github.com/chwarr/op-del-example
PS> cd op-del-example
PS> mkdir build
PS> cmake .. -G 'Visual Studio 14 2015 Win64'
PS> cmake --build . --target op-del-example -- /m
```

You should see a warning like:

```
     1>InitializeBuildStatus:
         Touching "op-del-example.dir\Debug\op-del-example.tlog\unsuccessfulbuild".
       CustomBuild:
         All outputs are up-to-date.
       ClCompile:
         C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\x86_amd64\CL.exe /c /I"C:\src\op-del-example\op-del-example\..\grpc\inclu
         de" /I"C:\src\op-del-example\grpc\third_party\protobuf\src" /Zi /nologo /W3 /WX- /Od /Ob0 /D WIN32 /D _WINDOWS /D _DEBUG /D _WIN32_W
         INNT=0x0600 /D "CMAKE_INTDIR=\"Debug\"" /D _MBCS /Gm- /EHsc /RTC1 /MDd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /GR /Fo"o
         p-del-example.dir\Debug\\" /Fd"op-del-example.dir\Debug\vc140.pdb" /Gd /TP /errorReport:queue "C:\src\op-del-example\op-del-example\
         op-del-example.cpp"
         op-del-example.cpp
     1>C:\src\op-del-example\grpc\include\grpc++/impl/codegen/async_unary_call.h(102): warning C4291: 'void *grpc::ClientAsyncResponseReader<
       int>::operator new(std::size_t,void *)': no matching operator delete found; memory will not be freed if initialization throws an excep
       tion [C:\src\build-ode\op-del-example\op-del-example.vcxproj]
         C:\src\op-del-example\grpc\include\grpc++/impl/codegen/async_unary_call.h(157): note: see declaration of 'grpc::ClientAsyncResponseR
         eader<int>::operator new'
         C:\src\op-del-example\op-del-example\op-del-example.cpp(38): note: see reference to function template instantiation 'grpc::ClientAsy
         ncResponseReader<int> *grpc::ClientAsyncResponseReader<int>::Create<int>(grpc::ChannelInterface *,grpc::CompletionQueue *,const grpc
         ::RpcMethod &,grpc::ClientContext *,const W &)' being compiled
                 with
                 [
                     W=int
                 ]
         C:\src\op-del-example\op-del-example\op-del-example.cpp(33): note: see reference to function template instantiation 'grpc::ClientAsy
         ncResponseReader<int> *grpc::ClientAsyncResponseReader<int>::Create<int>(grpc::ChannelInterface *,grpc::CompletionQueue *,const grpc
         ::RpcMethod &,grpc::ClientContext *,const W &)' being compiled
                 with
                 [
                     W=int
                 ]
       Link:
         C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\x86_amd64\link.exe /ERRORREPORT:QUEUE /OUT:"C:\src\build-ode\op-del-examp
         le\Debug\op-del-example.exe" /INCREMENTAL /NOLOGO kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib
         uuid.lib comdlg32.lib advapi32.lib ..\grpc\Debug\grpc++.lib ..\grpc\third_party\protobuf\Debug\libprotobufd.lib ..\grpc\Debug\grpc.l
         ib wsock32.lib ws2_32.lib ..\grpc\third_party\boringssl\ssl\Debug\ssl.lib ..\grpc\third_party\boringssl\crypto\Debug\crypto.lib ..\g
         rpc\third_party\zlib\Debug\zlibstaticd.lib ..\grpc\third_party\cares\Debug\cares.lib ..\grpc\Debug\gpr.lib /MANIFEST /MANIFESTUAC:"l
         evel='asInvoker' uiAccess='false'" /manifest:embed /DEBUG /PDB:"C:/src/build-ode/op-del-example/Debug/op-del-example.pdb" /SUBSYSTEM
         :CONSOLE /TLBID:1 /DYNAMICBASE /NXCOMPAT /IMPLIB:"C:/src/build-ode/op-del-example/Debug/op-del-example.lib" /MACHINE:X64  /machine:x
         64 "op-del-example.dir\Debug\op-del-example.obj"
         op-del-example.vcxproj -> C:\src\build-ode\op-del-example\Debug\op-del-example.exe
       FinalizeBuildStatus:
         Deleting file "op-del-example.dir\Debug\op-del-example.tlog\unsuccessfulbuild".
         Touching "op-del-example.dir\Debug\op-del-example.tlog\op-del-example.lastbuildstate".
     1>Done Building Project "C:\src\build-ode\op-del-example\op-del-example.vcxproj" (default targets).
```
