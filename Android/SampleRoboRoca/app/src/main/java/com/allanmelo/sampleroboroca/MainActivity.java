package com.allanmelo.sampleroboroca;

import android.content.Context;
import android.net.DhcpInfo;
import android.net.wifi.WifiManager;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

public class MainActivity extends AppCompatActivity {

	private static final int UDP_SERVER_PORT = 9999;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	// Pega o IP do roteador que estamos conectados, no caso o celular deve estar conectado na WIFI do RoboRoca
	public String getGateway() {
		WifiManager wifi = (WifiManager) getSystemService(Context.WIFI_SERVICE);
		DhcpInfo dhcpInfo = wifi.getDhcpInfo();

		return intParaIp(dhcpInfo.gateway);
	}

	// Converte o IP de inteiro para ipv4
	public String intParaIp(int addr) {

		return ((addr & 0xFF) + "." +
			((addr >>>= 8) & 0xFF) + "." +
			((addr >>>= 8) & 0xFF) + "." +
			((addr >>>= 8) & 0xFF));
	}

	// Envia mensagem em thread de background, pois o android tem restrição de chamadas na internet na thread principal
	private void enviarMensagem(final String mensagem) {
		System.out.println("enviarMensagem " + mensagem + " to: " + getGateway());

		new Thread(new Runnable() {

			@Override
			public void run() {
				sendUDP(mensagem);
			}

		}).start();
	}

	// Cria o pacote a partir da mensagem, e envia via UDP para o IP do roteador
	private void sendUDP(String mensagem) {
		DatagramSocket ds = null;

		try {
			ds = new DatagramSocket();
			InetAddress serverAddr = InetAddress.getByName(getGateway());
			DatagramPacket dp;
			dp = new DatagramPacket(mensagem.getBytes(), mensagem.length(),
				serverAddr, UDP_SERVER_PORT);

			ds.send(dp);
		} catch (SocketException e) {
			e.printStackTrace();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			if (ds != null) {
				ds.close();
			}
		}
	}

	// Eventos para quando clicar no botões da tela
	public void frente(View view) {
		enviarMensagem("frente");
	}

	public void tras(View view) {
		enviarMensagem("tras");
	}

	public void direita(View view) {
		enviarMensagem("direita");
	}

	public void esquerda(View view) {
		enviarMensagem("esquerda");
	}
}
