# -*- mode: python -*-

block_cipher = None

cli_a = Analysis(['keyplus_cli.py'],
             pathex=['C:\\Users\\user\\code\\keyplus\\host-software'],
             binaries=[],
             datas=[],
             hiddenimports=[],
             hookspath=[],
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher)

loader_a = Analysis(['loader.spec'],
             pathex=['C:\\Users\\user\\code\\keyplus\\host-software'],
             binaries=[],
             datas=[],
             hiddenimports=[],
             hookspath=[],
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher)

merged = MERGE( (cli_a, "keyplus_cli", "keyplus_cli"),
                (loader_a, "keyplus_loader", "keyplus_loader") )


cli_pyz = PYZ(cli_a.pure, cli_a.zipped_data,
             cipher=block_cipher)
cli_exe = EXE(cli_pyz,
          cli_a.scripts,
          exclude_binaries=True,
          name='keyplus_cli',
          debug=False,
          strip=False,
          upx=True,
          console=True )
cli_coll = COLLECT(cli_exe,
               cli_a.binaries,
               cli_a.zipfiles,
               cli_a.datas,
               strip=False,
               upx=True,
               name='keyplus_cli')

loader_pyz = PYZ(loader_a.pure, loader_a.zipped_data,
             cipher=block_cipher)
loader_exe = EXE(loader_pyz,
          loader_a.scripts,
          exclude_binaries=True,
          name='loader',
          debug=False,
          strip=False,
          upx=True,
          console=True )



loader_coll = COLLECT(loader_exe,
               loader_a.binaries,
               loader_a.zipfiles,
               loader_a.datas,
               strip=False,
               upx=True,
               name='loader')
