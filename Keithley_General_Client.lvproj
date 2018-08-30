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
		<Item Name="demo" Type="Folder"/>
		<Item Name="dll" Type="Folder">
			<Item Name="bin" Type="Folder">
				<Item Name="command_truncate.dll" Type="Document" URL="../dll/command_truncate.dll"/>
				<Item Name="csv_operator.dll" Type="Document" URL="../dll/csv_operator.dll"/>
				<Item Name="SCPI_LUTs.dll" Type="Document" URL="../dll/SCPI_LUTs.dll"/>
			</Item>
			<Item Name="include" Type="Folder">
				<Item Name="command_truncate.h" Type="Document" URL="../dll_src/command_truncate.h"/>
				<Item Name="csv_operator.h" Type="Document" URL="../dll_src/csv_operator.h"/>
				<Item Name="SCPI_LUTs.h" Type="Document" URL="../dll_src/SCPI_LUTs.h"/>
			</Item>
			<Item Name="src" Type="Folder">
				<Item Name="command_truncate.c" Type="Document" URL="../dll_src/command_truncate.c"/>
				<Item Name="csv_operator.c" Type="Document" URL="../dll_src/csv_operator.c"/>
				<Item Name="SCPI_LUTs.c" Type="Document" URL="../dll_src/SCPI_LUTs.c"/>
			</Item>
		</Item>
		<Item Name="documentation" Type="Folder">
			<Item Name="class_doc" Type="Folder">
				<Item Name="class_machine.rtf" Type="Document" URL="../documentation/class_doc/class_machine.rtf"/>
				<Item Name="class_technique_parameters.rtf" Type="Document" URL="../documentation/class_doc/class_technique_parameters.rtf"/>
			</Item>
			<Item Name="Front_panel_architecture.rtf" Type="Document" URL="../documentation/Front_panel_architecture.rtf"/>
			<Item Name="SCPI_file_architecture.rtf" Type="Document" URL="../documentation/SCPI_file_architecture.rtf"/>
		</Item>
		<Item Name="lib" Type="Folder">
			<Item Name="FileIO" Type="Folder">
				<Item Name="file_interative_manager.vi" Type="VI" URL="../fileIO/file_interative_manager.vi"/>
				<Item Name="IO_csv_writer.vi" Type="VI" URL="../fileIO/IO_csv_writer.vi"/>
				<Item Name="IO_txt_writer.vi" Type="VI" URL="../fileIO/IO_txt_writer.vi"/>
			</Item>
			<Item Name="Generators" Type="Folder">
				<Item Name="sine_source.vi" Type="VI" URL="../generators/sine_source.vi"/>
				<Item Name="square_source.vi" Type="VI" URL="../generators/square_source.vi"/>
				<Item Name="triangle_source.vi" Type="VI" URL="../generators/triangle_source.vi"/>
			</Item>
			<Item Name="Optimization" Type="Folder">
				<Item Name="double_array.lvclass" Type="LVClass" URL="../optimization/doubling_array/double_array.lvclass"/>
				<Item Name="table_doubling.vi" Type="VI" URL="../optimization/table_doubling.vi"/>
			</Item>
			<Item Name="Scan_Technique" Type="Folder">
				<Item Name="choose_technique.vi" Type="VI" URL="../scan_technique/choose_technique.vi"/>
				<Item Name="constant_voltage.vi" Type="VI" URL="../scan_technique/constant_voltage.vi"/>
				<Item Name="cyclic_voltammetry.vi" Type="VI" URL="../scan_technique/cyclic_voltammetry.vi"/>
				<Item Name="differential_pulse_voltammetry.vi" Type="VI" URL="../scan_technique/differential_pulse_voltammetry.vi"/>
				<Item Name="technique_parameters.lvclass" Type="LVClass" URL="../scan_technique/technique_parameters/technique_parameters.lvclass"/>
			</Item>
		</Item>
		<Item Name="machine_ops" Type="Folder">
			<Item Name="machine.lvclass" Type="LVClass" URL="../machine_ops/machine.lvclass"/>
		</Item>
		<Item Name="specific_clients" Type="Folder"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Check if File or Folder Exists.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Check if File or Folder Exists.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="ex_CorrectErrorChain.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_CorrectErrorChain.vi"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="NI_PackedLibraryUtility.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/LVLibp/NI_PackedLibraryUtility.lvlib"/>
				<Item Name="subDisplayMessage.vi" Type="VI" URL="/&lt;vilib&gt;/express/express output/DisplayMessageBlock.llb/subDisplayMessage.vi"/>
				<Item Name="subFile Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/express/express input/FileDialogBlock.llb/subFile Dialog.vi"/>
				<Item Name="VISA Configure Serial Port" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port"/>
				<Item Name="VISA Configure Serial Port (Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Instr).vi"/>
				<Item Name="VISA Configure Serial Port (Serial Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Serial Instr).vi"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
