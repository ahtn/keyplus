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

flasher_a = Analysis(['flasher.spec'],
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
                (flasher_a, "keyplus_flasher", "keyplus_flasher") )


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

flasher_pyz = PYZ(flasher_a.pure, flasher_a.zipped_data,
             cipher=block_cipher)
flasher_exe = EXE(flasher_pyz,
          flasher_a.scripts,
          exclude_binaries=True,
          name='flasher',
          debug=False,
          strip=False,
          upx=True,
          console=True )



flasher_coll = COLLECT(flasher_exe,
               flasher_a.binaries,
               flasher_a.zipfiles,
               flasher_a.datas,
               strip=False,
               upx=True,
               name='flasher')
