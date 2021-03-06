require File.expand_path('../../../spec_helper', __FILE__)

describe "FFI::Platform::LIBSUFFIX" do
  platform_is :linux do
    it "returns 'so'" do
      FFI::Platform::LIBSUFFIX.should == 'so'
    end
  end

  platform_is :windows do
    it "returns 'dll'" do
      FFI::Platform::LIBSUFFIX.should == 'dll'
    end
  end

  platform_is :darwin do
    it "returns 'dylib'" do
      FFI::Platform::LIBSUFFIX.should == 'dylib'
    end
  end
end

