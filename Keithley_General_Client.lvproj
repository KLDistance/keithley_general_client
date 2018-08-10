<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="14008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Demo" Type="Folder">
			<Item Name="test_generator.vi" Type="VI" URL="../test_generator.vi"/>
		</Item>
		<Item Name="DMM7510_client" Type="Folder"/>
		<Item Name="libs" Type="Folder">
			<Item Name="FileIO" Type="Folder"/>
			<Item Name="Generators" Type="Folder">
				<Item Name="sine_source.vi" Type="VI" URL="../sine_source.vi"/>
				<Item Name="square_source.vi" Type="VI" URL="../square_source.vi"/>
				<Item Name="triangle_source.vi" Type="VI" URL="../triangle_source.vi"/>
			</Item>
			<Item Name="Optimization" Type="Folder">
				<Item Name="double_array.lvclass" Type="LVClass" URL="../doubling_array/double_array.lvclass"/>
				<Item Name="table_doubling.vi" Type="VI" URL="../table_doubling.vi"/>
			</Item>
		</Item>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
